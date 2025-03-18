#include "nwpwin.h"
#include "res.h"

class Edit : public vsite::nwp::window {
protected:
	std::string class_name() override { return "Edit"; }
};
class Button : public vsite::nwp::window {
protected:
	std::string class_name() override { return "Button"; }
};
class ListBox : public vsite::nwp::window {
protected:
	std::string class_name() override { return "ListBox"; }
};


class main_window : public vsite::nwp::window
{
protected:
	int on_create(CREATESTRUCT* pcs) override;
	void on_command(int id) override;
	void on_destroy() override;

private:
	Edit edit;
	Button add;
	Button remove;
	ListBox list_box;
};

int main_window::on_create(CREATESTRUCT* pcs)
{
	edit.create(*this, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, IDC_EDIT, 130, 50, 100, 48);
	list_box.create(*this, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, IDC_LB, 20, 50, 100, 166);
	add.create(*this, WS_CHILD | WS_VISIBLE | WS_BORDER, "Add", IDC_ADD, 130, 100, 100, 32);
	remove.create(*this, WS_CHILD | WS_VISIBLE | WS_BORDER, "Remove", IDC_REMOVE, 130, 134, 100, 32);
	
	EnableWindow(remove, false);

	return 0;
}

void main_window::on_command(int id){
	switch (id) {
	case ID_FILE_EXIT:
		on_destroy();
		break;
	case ID_HELP_ABOUT:
		MessageBox(*this, "Add -> add to list\nRemove -> removes from list.", "Help", MB_OK | MB_ICONINFORMATION);
		break;
	case IDC_ADD:
		char text[64];
		GetDlgItemText(*this, IDC_EDIT, text, sizeof(text));
		SendDlgItemMessage(*this, IDC_LB, LB_ADDSTRING, 0, (LPARAM)text);
		EnableWindow(remove, TRUE);
		break;
	case IDC_REMOVE:
		int list_box_selection = SendMessage(list_box, LB_GETCURSEL, 0, 0);
		if (list_box_selection != LB_ERR) {
			SendMessage(list_box, LB_DELETESTRING, list_box_selection, 0);
		}
		int list_box_element_num = SendMessage(list_box, LB_GETCOUNT, 0, 0);
		if (list_box_element_num == 0) {
			EnableWindow(remove, FALSE);
		}
		break;
	}
}

void main_window::on_destroy(){
	::PostQuitMessage(0);
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_window w; 
	w.create(0, WS_OVERLAPPEDWINDOW | WS_VISIBLE, "NWP 2", (int)::LoadMenu(instance, MAKEINTRESOURCE(IDM_V2)));
	vsite::nwp::set_icons(instance, w, IDI_V2);
	vsite::nwp::application app;
	return app.run();
}
