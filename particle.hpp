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
	char fixation = 0; // 1�̸� �ùķ��̼ǽ� �����Ǿ� x,y ��ǥ ��ȭ ����, 0�̸� ���� ����
private:
	double m;
	double x;
	double y;
	double vx;
	double vy;
	double force_p[2] = { 0.0,0.0 };  //���ڳ����� ��ȣ�ۿ����� �޴� ��
	particle *ref = this;//�ڱ��ڽ��� �ּҸ� ��������� ������ �ִ�.
	string id;	
	
};