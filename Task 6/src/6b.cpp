#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::asio::ip;

class WebServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\r\n",
                     [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec) {
        // Retrieve message from client as string:
        istream read_stream(read_buffer.get());
        std::string request_line;
        getline(read_stream, request_line);

        // Extract the HTTP method and path from the request line
        std::string http_method;
        std::string path;
        istringstream request_stream(request_line);
        request_stream >> http_method >> path;

        if (http_method == "GET" && path == "/") {
          // Respond to the root path
          send_response(connection, "200 OK", "text/plain", "Dette er hovedsiden");
        } else if (http_method == "GET" && path == "/en_side") {
          // Respond to the /en_side path
          send_response(connection, "200 OK", "text/plain", "Dette er en side");
        } else {
          // Respond with 404 Not Found for all other paths
          send_response(connection, "404 Not Found", "text/plain", "Not Found");
        }
      }
    });
  }

  void send_response(shared_ptr<Connection> connection, const std::string& status, const std::string& content_type, const std::string& body) {
    auto response = make_shared<boost::asio::streambuf>();
    ostream response_stream(response.get());

    response_stream << "HTTP/1.1 " << status << "\r\n";
    response_stream << "Content-Type: " << content_type << "\r\n";
    response_stream << "Content-Length: " << body.length() << "\r\n";
    response_stream << "Connection: close\r\n\r\n";
    response_stream << body;

    async_write(connection->socket, *response,
                [this, connection, response](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec)
        handle_request(connection);
    });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_service);
    
    // Accepts a new (client) connection. On connection, immediately start accepting a new connection 
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  WebServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();

    io_service.run();
  }
};

int main() {
  WebServer web_server;

  cout << "Starting web server" << endl
       << "Access in a web browser at http://localhost:8080 or http://localhost:8080/en_side" << endl;

  web_server.start();
}
