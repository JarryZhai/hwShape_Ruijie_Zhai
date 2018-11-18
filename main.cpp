#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

/*

	Cube
	Cylinder
	Sphere (optional)
https://en.wikipedia.org/wiki/STL_(file_format)

 */
class Vector{
public:
    double x, y, z;

};


class Cube{
private:
    //double cx, cy, cz;
public:
    uint32_t s;
    Cube(double s):s(s){
    }

    //void translate(const int& x, const int& y, const int& z){
    //    cx=x;
    //    cy=y;
    //    cz=z;
    //}

    double volume(){
        double v=s*s*s;
        return v;
    }

    void write(const char *a) {
        ofstream out;
        out.open(a);
        out<<"out"<<endl;
        out.close();
    }

};

class Cylinder{
private:

public:
    uint32_t r,h;
    Cylinder(double r, double h):r(r), h(h){
    }
};




class Design{
private:
    string d;
public:
    Design(){
         uint8_t head [80]={0};
         uint32_t num=30;
         d= nullptr;
         for(int i=0; i<80; i++){
             d += head[i];
         }
         d+= num;
    }

    void add(Cube c){
        for(uint32_t k=0; k<c.s; k++){
            //first tri
            uint32_t mor1[3]={0,0,1};
            for(int i=0; i<3; i++){
                d+=mor1[i];
            }
            uint32_t c11[3]={-c.s/2,-c.s/2,k};
            uint32_t c12[3]={c.s/2,-c.s/2,k};
            uint32_t c13[3]={-c.s/2,c.s/2,k};
            uint16_t end1=0;
            for(int i=0; i<3; i++){
                d+=c11[i];
            }
            for(int i=0; i<3; i++){
                d+=c12[i];
            }
            for(int i=0; i<3; i++){
                d+=c13[i];
            }
            d+=end1;

            //second tri
            uint32_t mor2[3]={0,0,1};
            for(int i=0; i<3; i++){
                d+=mor2[i];
            }
            uint32_t c21[3]={c.s/2,-c.s/2,k};
            uint32_t c22[3]={-c.s/2,c.s/2,k};
            uint32_t c23[3]={c.s/2,c.s/2,k};
            uint16_t end2=0;
            for(int i=0; i<3; i++){
                d+=c21[i];
            }
            for(int i=0; i<3; i++){
                d+=c22[i];
            }
            for(int i=0; i<3; i++){
                d+=c23[i];
            }
            d+=end2;
        }

    }

    void add(Cylinder cyl){
        uint32_t cos=0.766*cyl.r;
        uint32_t sin=0.643*cyl.r;
        for(uint32_t j=0; j<cyl.h; j++){
            //first tri
            uint32_t cymor1[3]={0,0,1};
            for(int i=0; i<3; i++) {
                d += cymor1[i];
            }
            uint32_t cy11[3]={0,cyl.r,j+10};
            uint32_t cy12[3]={-cos,sin,j+10};
            uint32_t cy13[3]={-cyl.r,0,j+10};
            uint16_t end1=0;
            for(int i=0; i<3; i++){
                d+=cy11[i];
            }
            for(int i=0; i<3; i++){
                d+=cy12[i];
            }
            for(int i=0; i<3; i++){
                d+=cy13[i];
            }
            d+=end1;

            //second tri
            uint32_t cymor2[3]={0,0,1};
            for(int i=0; i<3; i++) {
                d += cymor2[i];
            }
            uint32_t cy21[3]={0,cyl.r,j+10};
            uint32_t cy22[3]={-cyl.r,0,j+10};
            uint32_t cy23[3]={-cos,-sin,j+10};
            uint16_t end2=0;
            for(int i=0; i<3; i++){
                d+=cy21[i];
            }
            for(int i=0; i<3; i++){
                d+=cy22[i];
            }
            for(int i=0; i<3; i++){
                d+=cy23[i];
            }
            d+=end2;

            //third tri
            uint32_t cymor3[3]={0,0,1};
            for(int i=0; i<3; i++) {
                d += cymor3[i];
            }
            uint32_t cy31[3]={0,cyl.r,j+10};
            uint32_t cy32[3]={-cos,-sin,j+10};
            uint32_t cy33[3]={0,-cyl.r,j+10};
            uint16_t end3=0;
            for(int i=0; i<3; i++){
                d+=cy31[i];
            }
            for(int i=0; i<3; i++){
                d+=cy32[i];
            }
            for(int i=0; i<3; i++){
                d+=cy33[i];
            }
            d+=end3;


            //fourth tri
            uint32_t cymor4[3]={0,0,1};
            for(int i=0; i<3; i++) {
                d += cymor4[i];
            }
            uint32_t cy41[3]={0,cyl.r,j+10};
            uint32_t cy42[3]={0,-cyl.r,j+10};
            uint32_t cy43[3]={cos,-sin,j+10};
            uint16_t end4=0;
            for(int i=0; i<3; i++){
                d+=cy41[i];
            }
            for(int i=0; i<3; i++){
                d+=cy42[i];
            }
            for(int i=0; i<3; i++){
                d+=cy43[i];
            }
            d+=end4;


            //fifth tri
            uint32_t cymor5[3]={0,0,1};
            for(int i=0; i<3; i++) {
                d += cymor5[i];
            }
            uint32_t cy51[3]={0,cyl.r,j+10};
            uint32_t cy52[3]={cos,-sin,j+10};
            uint32_t cy53[3]={cyl.r,0,j+10};
            uint16_t end5=0;
            for(int i=0; i<3; i++){
                d+=cy51[i];
            }
            for(int i=0; i<3; i++){
                d+=cy52[i];
            }
            for(int i=0; i<3; i++){
                d+=cy53[i];
            }
            d+=end5;


            //sixth tri
            uint32_t cymor6[3]={0,0,1};
            for(int i=0; i<3; i++) {
                d += cymor6[i];
            }
            uint32_t cy61[3]={0,cyl.r,j+10};
            uint32_t cy62[3]={cyl.r,0,j+10};
            uint32_t cy63[3]={cos,sin,j+10};
            uint16_t end6=0;
            for(int i=0; i<3; i++){
                d+=cy61[i];
            }
            for(int i=0; i<3; i++){
                d+=cy62[i];
            }
            for(int i=0; i<3; i++){
                d+=cy63[i];
            }
            d+=end6;
        }
    }

    void write(const char *a) {
        ofstream out;
        out.open(a);
        out<<d;
        out.close();
    }
};

int main() {
    Design d;
    double s = 10;
    Cube c(s);
//    c.translate(x,y,z);
    // rotate??
    cout << c.volume() << '\n';
    c.write("out.stl"); // how to get all my shapes into the same file
    d.add(c);
    double r = 10, height  = 20;
    Cylinder cyl(r, height);
    d.add(cyl);
    d.write("test.stl");
}