class particle
{
    friend class particleset;
public:
    particle();
    particle(double, double, double, double = 0.0, double = 0.0);
    particle(particle&);
    ~particle();
    void set_m(double mass) { m = mass; }
    void set_p(double px, double py) { x = px; y = py; }
    void set_v(double pvx, double pvy) { vx = pvx; vy = pvy; }
    double get_m() { return m; }
    double get_x() { return x; }
    double get_y() { return y; }
    double get_vx() {return vx; }
    double get_vy() { return vy; };
    void printall();
    
private:
    double m;
    double x;
    double y;
    double vx;
    double vy;
    double f = 0;
    particle* id = this;
    
};
