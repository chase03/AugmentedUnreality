/*
Copyright 2016 Krzysztof Lis

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once
/* 
Including OpenCV in UE4 can cause some conflicts.
However, we resolve them wit the following tricks
*/

// UE4 defines a macro "check" in Runtime/Core/Public/Misc/AssertionMacros.h:28
// which conflicts with method "check" in opencv2/core/utility.hpp:729
// so remove the macro for this file:
#undef check

// Both UE4 and OpenCV typedef types "int64" "uint64" and that causes a conflict.
// To prevent the conflict, we rename OpenCV's types.
#define int64 OpenCV_int64
#define uint64 OpenCV_uint64

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/aruco.hpp>

#undef int64
#undef uint64

// But UE needs this macro, so here it comes back
#define check(expr)	{ if(UNLIKELY(!(expr))) { FDebug::LogAssertFailedMessage( #expr, __FILE__, __LINE__ ); _DebugBreakAndPromptForRemote(); FDebug::AssertFailed( #expr, __FILE__, __LINE__ ); CA_ASSUME(expr); } }
