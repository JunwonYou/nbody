#pragma once

class particle
{
	friend class whole;
	friend class particleset;
public:
	particle();
	particle(double, double, double, double = 0.0, double = 0.0);
	particle(particle&);
	~particle();
	void setmass(double mass) { m = mass; }
	void setlocation(double px, double py) { x = px; y = py; }
	void setvelocity(double pvx, double pvy) { v_x = pvx; v_y = pvy; }
	double getmass() { return m; };
	double getlocation() { return x, y; };
	double getvelocity() { return v_x, v_y; };
	void printinfor();

private:
	double m;
	double x;
	double y;
	double v_x;
	double v_y;
	double f = 0;
	particle *ref = this;
	int id = -1;

};