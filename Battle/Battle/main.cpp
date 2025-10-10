#include "framework.h"

//			Creature(추상클래스)
//	   Player (추상클래스)     Monster (추상클래스)
// Knight  Archer  Mage       Goblin

// 1. Player가 1~3까지 숫자 선택으로 클래스 정하기
// 2. Goblin 10마리와 Player가 싸우는데, 서로 죽을 때까지

// Knight는 피가 50프로 이하면 1.3배의 데미지
// Archer는 30프로 확률로 2배의 크리티컬 데미지
// Mage는 마나가 있고, 마나가 여유분 있을 때 10의 마나를 써서 1.5배의 데미지

int main()
{
	Creature c;
	c.Hello();

	Monster m;
	m.Hello();
	Player p;
	p.Hello();

	p.HelloMonster(&m);

	return 0;
}