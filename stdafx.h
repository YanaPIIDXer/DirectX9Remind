#ifndef STDAFX_H
#define STDAFX_H

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <tchar.h>

// ˆÀ‘S‚È‰ð•ú
#define SAFE_RELEASE(p) if (p != nullptr) { p->Release(); p = nullptr; }

#endif		// #ifndef STDAFX_H
