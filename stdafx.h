#ifndef STDAFX_H
#define STDAFX_H

#include <Windows.h>
#include <tchar.h>

// ���S�ȉ��
#define SAFE_RELEASE(p) if (p != nullptr) { p->Release(); p = nullptr; }

#endif		// #ifndef STDAFX_H
