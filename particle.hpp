#pragma once

class particle // Class of partices.
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
	double f = 0;
	particle *ref = this;
	int id = -1;

};
