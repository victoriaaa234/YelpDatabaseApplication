// Members: My Pham, Sneha Santani, Leslie Escalante
// Team 17 - section 506

#pragma once  
#ifdef DLIBRARY_EXPORTS
#define DLIBRARY __declspec(dllexport)   
#else  
#define DLIBRARY __declspec(dllimport)   
#endif   

#include "record.h"
#include "table.h"
#include "database.h"