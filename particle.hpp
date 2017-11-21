#pragma once

class particle
{
	friend class Set_whole;
	friend class Set_particle;
public:
	particle();
	particle(double, double, double, double = 0.0, double = 0.0);
	particle(particle&);
	~particle();
	void set_mass(double mass) { m = mass; }
	void set_location(double px, double py) { x = px; y = py; }
	void set_velocity(double pvx, double pvy) { vx = pvx; vy = pvy; }
	double get_mass() { return m; };
	double get_location() { return x, y; };
	double get_velocity() { return vx, vy; };
	void print_infor();

private:
	double m;
	double x;
	double y;
	double vx;
	double vy;
	double force_p[2] = { 0.0,0.0 };  //입자끼리의 상호작용으로 받는 힘
	particle *ref = this;//자기자신의 주소를 멤버변수로 가지고 있다.
	int id = -1;	   // whole에서 입자 생성 시 부여받을 유일한 id 
	char pixation = 0; // 1이면 시뮬레이션시 고정되어 x,y 좌표 변화 없음, 0이면 고정 해제
};