#pragma once

//#define SAFE_MODE

#ifdef SAFE_MODE

#else
#pragma warning (disable : 4996)
#endif

void stdin_clear();
