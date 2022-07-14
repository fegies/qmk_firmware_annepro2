#pragma once

#define BACKGROUND_COLOR_NEO 0xFF, 0x00, 0x00
#define BACKGROUND_COLOR_QWERTY 0x00, 0x00, 0xFF

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DISABLE_LEADER

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
