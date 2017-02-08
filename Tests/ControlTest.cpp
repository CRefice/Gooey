#include <App.hpp>
#include <Button.hpp>
#include <FileDialog.hpp>
#include <Window.hpp>
#include <ComboBox.hpp>
#include <ImageBox.hpp>
#include <InputBox.hpp>
#include <ListView.hpp>
#include <Label.hpp>

using namespace goo;

class MyWindow : public Window
{
public:
	MyWindow() {
		setText("Test");
		setSize({ 520, 320 });

		comboBox.setBounds({ 80, 70 }, { 120, 20 });
		label.setBounds({ 70, 20 }, {150, 50});
		button.setBounds({ 120, 220 }, { 80, 25 });
		imgBox.setBounds({ 110, 100 }, { 100, 100 });
		listView.setBounds({ 280, 15 }, { 200, 200 });
		inputBox.setBounds({ 280, 235 }, { 200, 20 });

		comboBox.addItem("This is an item!");
		comboBox.addItem("This is also an item!");

		listView.addColumn(ColumnHeader("Header 1", 60));
		listView.addColumn(ColumnHeader("Header 2", 60));
		listView.addColumn(ColumnHeader("Header 3", 60));
		listView.addItem(ListViewItem("SubItem 1"));

		comboBox.onSelectionChanged.setHandler([this](int index)
		{
			label.setText("Selected item #" + std::to_string(index)
				+ "\nItem text: " + comboBox.selectedString());
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
		attach(listView);
		attach(inputBox);
	}

	Label label{ "This is a label!" };
	Button button{ "Select Image" };
	ComboBox comboBox;
	ImageBox imgBox;
	ListView listView;
	InputBox inputBox;
};

int main()
{
	MyWindow wnd;
	wnd.show();
	App::run();
}
