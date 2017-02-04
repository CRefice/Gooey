#include <App.hpp>
#include <Button.hpp>
#include <FileDialog.hpp>
#include <Window.hpp>
#include <ComboBox.hpp>
#include <ImageBox.hpp>
#include <Label.hpp>

using namespace goo;

class MyWindow : public Window
{
public:
	MyWindow() {
		setText("Test");
		setSize({340, 320});

		comboBox.setBounds({ 50, 50 }, { 120, 20 });
		label.setBounds({ 180, 53 }, {100, 20});

		button.setBounds({120, 220}, {80, 25});
		imgBox.setBounds({ 110, 100 }, { 100, 100 });

		comboBox.addItem("This is an item!");
		comboBox.addItem("This is also an item!");

		comboBox.onSelectionChanged.setHandler([this](int index)
		{
			label.setText("Selected item #" + std::to_string(index));
		});
		button.onClick.setHandler([this]()
		{
			OpenFileDialog dlg{ "Open an image file", "Bitmap files (*.bmp)|*.bmp" };
			if (dlg.show() == DialogResult::OK)
			{
				imgBox.setImage(Image(dlg.fileName()));
			}
		});

		attach(label);
		attach(button);
		attach(comboBox);
		attach(imgBox);
	}

	Label label{ "This is a label!" };
	Button button{ "Select Image" };
	ComboBox comboBox;
	ImageBox imgBox;
};

int main()
{
	MyWindow wnd;
	wnd.show();
	App::run();
}
