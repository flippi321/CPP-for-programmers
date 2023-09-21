#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    bool validInputs;
    Gtk::Box box;
    Gtk::Entry firstName;
    Gtk::Entry lastName;
    Gtk::Button button;
    Gtk::Label label;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        button.set_label("Combine names");

        box.pack_start(firstName);  // Add the widget entry to box
        box.pack_start(lastName);  // Add the widget entry to box
        box.pack_start(button); // Add the widget button to box
        box.pack_start(label);  // Add the widget label to box

        add(box);   // Add vbox to window
        show_all(); // Show all widgets
        button.set_sensitive(false); // Disable button before the user enters anything

        // If the first name is changed, we check if inputs are valid
        firstName.signal_changed().connect([this]() {
            validInputs = (!firstName.get_text().empty() && !lastName.get_text().empty());
            button.set_sensitive(validInputs);
        });

        // If the last name is changed, we check if inputs are valid
        lastName.signal_changed().connect([this]() {
            validInputs = (!firstName.get_text().empty() && !lastName.get_text().empty());
            button.set_sensitive(validInputs);
        });

        // If button is clicked we combine the first and last name
        // Will only work if button is active (sensitive)
        button.signal_clicked().connect([this]() {
            Glib::ustring labelText = firstName.get_text() + " " + lastName.get_text();
            label.set_text(labelText);
        });
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}
