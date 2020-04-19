#include<iostream>
#include <string>
#include<windows.h>
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")


using namespace std;

int main()
{
		string narrow_string;

		cout << "***Chuong trinh download CSGO config by Nguyen Khang Hy***" << endl << endl;

		cout << "Nhap duong dan chua thu muc cfg: "; getline(cin, narrow_string);;

		narrow_string = narrow_string + "\\hy.cfg";
		wstring wide_string = wstring(narrow_string.begin(), narrow_string.end());
		const wchar_t* result = wide_string.c_str();


		HRESULT hr;
		LPCTSTR Url = _T("https://github.com/khanghy1000/CSGO-Config/raw/Hy/hy.cfg"), File = result;
		hr = URLDownloadToFile(0, Url, File, 0, 0);
		switch (hr)
		{
		case S_OK:
			cout << "Successful download\n";
			break;
		case E_OUTOFMEMORY:
			cout << "Out of memory error\n";
			break;
		case INET_E_DOWNLOAD_FAILURE:
			cout << "Cannot access server data\n";
			break;
		default:
			cout << "Unknown error\n";
			break;
		}

		system("pause");
		return 0;
}
