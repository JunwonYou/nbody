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
	double force_p[2] = { 0.0,0.0 };  //���ڳ����� ��ȣ�ۿ����� �޴� ��
	particle *ref = this;//�ڱ��ڽ��� �ּҸ� ��������� ������ �ִ�.
	int id = -1;	   // whole���� ���� ���� �� �ο����� ������ id 
	char pixation = 0; // 1�̸� �ùķ��̼ǽ� �����Ǿ� x,y ��ǥ ��ȭ ����, 0�̸� ���� ����
};