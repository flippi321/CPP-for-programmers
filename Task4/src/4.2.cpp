#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    bool validInputs;
    Gtk::Box box;
    Gtk::Label firstNameTitle;
    Gtk::Entry firstName;
    Gtk::Label lastNameTitle;
    Gtk::Entry lastName;
    Gtk::Button button;
    Gtk::Label label;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        // Define labels
        button.set_label("Combine names");
        firstNameTitle.set_text("Your First name:");
        lastNameTitle.set_text("Your Last name:");

        // Add everything to the box
        box.pack_start(firstNameTitle);
        box.pack_start(firstName);
        box.pack_start(lastNameTitle);
        box.pack_start(lastName);
        box.pack_start(button);
        box.pack_start(label);

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
            Glib::ustring labelText = "Hi " + firstName.get_text() + " " + lastName.get_text() + "!";
            label.set_text(labelText);
        });
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}
