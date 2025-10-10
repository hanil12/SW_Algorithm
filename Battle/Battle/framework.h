#pragma once

// 미리 컴파일할 헤더 파일들 모두 모아놓는 역할
// 미리 컴파일된 헤더 만들기
// 1. framwork.cpp 속성 -> C/C++ -> 미리컴파일된 헤더 만들기/ framework.h
// 2. 프로젝트 속성 -> C/C++ -> 미리컴파일된 헤더 사용/ framework.h

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#include "Creature.h"
#include "Player.h"
#include "Monster.h"