#include "MyForm.h"

using namespace KursovayaGUI;

[STAThreadAttribute]
int main(array <System::String^>^ args)
{
	//��������� ���������� �������� Windows XP
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew MyForm());
	return 0;
}
