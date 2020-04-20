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
	bool loop;
	do
	{
		system("cls");
		string narrow_string, narrow_string1;
		bool choose;

		cout << "***CSGO Config Installer by Nguyen Khang Hy***" << endl << endl;

		cout << "Choose CSGO CFG output path: " << endl;
		cout << "[0]: Default" << endl;
		cout << "[1]: Other path" << endl;
		cout << "Choose: "; cin >> choose;
		cout << endl;
		cin.ignore(INT64_MAX, '\n');

		if (!choose)
		{
			string path = "Program Files (x86)", Cdrive = "C:";
			char GachCheoNguoc(92);
			narrow_string = Cdrive + GachCheoNguoc + path + GachCheoNguoc + "Steam" + GachCheoNguoc + "steamapps" + GachCheoNguoc + "common" + GachCheoNguoc + "Counter-Strike Global Offensive" + GachCheoNguoc + "csgo" + GachCheoNguoc + "cfg";
			cout << "Default path: " << narrow_string << endl << endl;
		}

		else if (choose)
		{
			cout << "Enter the path: "; getline(cin, narrow_string);
			cout << endl;
		}

		narrow_string1 = narrow_string + "\\hy.cfg";
		wstring wide_string1 = wstring(narrow_string1.begin(), narrow_string1.end());
		const wchar_t* result1 = wide_string1.c_str();

		cout << "Downloading hy.cfg....\t\t\t";

		HRESULT hr;
		LPCTSTR Url1 = _T("https://github.com/khanghy1000/CSGO-Config/raw/Hy/hy.cfg"), File1 = result1;
		hr = URLDownloadToFile(0, Url1, File1, 0, 0);
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

		cout << "Downloading training.cfg....\t\t";

		string narrow_string2;
		narrow_string2 = narrow_string + "\\training.cfg";
		wstring wide_string2 = wstring(narrow_string2.begin(), narrow_string2.end());
		const wchar_t* result2 = wide_string2.c_str();

		HRESULT hr2;
		LPCTSTR Url2 = _T("https://github.com/khanghy1000/CSGO-Config/raw/Hy/training.cfg"), File2 = result2;
		hr2 = URLDownloadToFile(0, Url2, File2, 0, 0);
		switch (hr2)
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

		cout << endl;

		cout << "Do you want to close this program?" << endl;
		cout << "[0]: No" << endl;
		cout << "[1]: Yes" << endl;
		cout << "Choose: "; cin >> loop;

	} while (!loop);

	return 0;
}
