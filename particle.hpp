#pragma once
#include <string>
using namespace std;
class particle
{
	friend class Set_whole;
	friend class Set_particle;
public:

	particle(std::string pid, double pm , double px , double py, double pvx, double pvy) :id(pid),m(pm),x(px),y(py),vx(pvx),vy(pvy) {};
	~particle();
	void set_mass(double mass) { m = mass; }
	void set_location(double px, double py) { x = px; y = py; }
	void set_velocity(double pvx, double pvy) { vx = pvx; vy = pvy; }
	double get_mass() { return m; };
	double get_location() { return x, y; };
	double get_velocity() { return vx, vy; };
	string get_id() { return id; }
	void print_infor();
	char fixation = 0; // 1이면 시뮬레이션시 고정되어 x,y 좌표 변화 없음, 0이면 고정 해제
private:
	double m;
	double x;
	double y;
	double vx;
	double vy;
	double force_p[2] = { 0.0,0.0 };  //입자끼리의 상호작용으로 받는 힘
	particle *ref = this;//자기자신의 주소를 멤버변수로 가지고 있다.
	string id;	
	
};