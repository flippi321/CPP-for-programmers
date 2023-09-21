#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Entry entry;
    Gtk::Button button;
    Gtk::Label label;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        button.set_label("Click here");

        box.pack_start(entry);  // Add the widget entry to box
        box.pack_start(button); // Add the widget button to box
        box.pack_start(label);  // Add the widget label to box

        add(box);   // Add vbox to window
        show_all(); // Show all widgets

        entry.signal_changed().connect([this]() {
            label.set_text("Entry now contains: " + entry.get_text());
        });

        entry.signal_activate().connect([this]() {
            label.set_text("Entry activated");
        });

        button.signal_clicked().connect([this]() {
            label.set_text("Button clicked");
        });
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}
