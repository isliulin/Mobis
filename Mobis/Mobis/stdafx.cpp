
// stdafx.cpp : source file that includes just the standard includes
// Mobis.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"




int g_CamNum =2;
std::vector<CRITICAL_SECTION>  g_CamBufs(g_CamNum);  //�����ٽ��� 
std::vector<HANDLE> g_CamAcqs(g_CamNum);
std::vector<HANDLE> g_ReadyChecks(g_CamNum);