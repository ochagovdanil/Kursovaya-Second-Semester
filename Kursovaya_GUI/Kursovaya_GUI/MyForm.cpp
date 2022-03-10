#include "MyForm.h"

using namespace KursovayaGUI;

[STAThreadAttribute]
int main(array <System::String^>^ args)
{
	//Включение визуальных эффектов Windows XP
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Создание главного окна и его запуск
	Application::Run(gcnew MyForm());
	return 0;
}
