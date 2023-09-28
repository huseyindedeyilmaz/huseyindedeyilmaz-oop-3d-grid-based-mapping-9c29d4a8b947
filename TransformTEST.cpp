#include "Transform.h"
#include "Transform.cpp"
#include "PointCloud.h"
#include "Point.h"
#include "PointCloud.cpp"
#include "Point.cpp"
int main(int argc, char const *argv[])
{
    /*
    //test point
    Point p1(0,2,3);
    Point p2(1,8,9);
    //
    if (p1==p2)
    {
        std::cout << "True" << std::endl;
    }
    else std::cout << "false" << std::endl;
    
    std::cout <<"Distance P1 to P2: " << p1.distance(p2) <<endl <<"Distance P2 to P1: " << p2.distance(p1) <<endl<< std::endl;
    
    std::cout <<"P1 x:"<< p1.getPointx()<< " " <<"P1 y:"<< p1.getPointy()<< " "   <<"P1 z:"<< p1.getPointz()<<std::endl;
    std::cout <<"P2 x:"<< p2.getPointx()<< " " <<"P2 y:"<< p2.getPointy()<< " "   <<"P2 z:"<< p2.getPointz()<<std::endl;
    //
    */
   /*
    //test point
    Point p01(0,0,0);
    Point p02(0,0,0);
    //
    if (p1==p2)
    {
        std::cout << "True" << std::endl;
    }
    else std::cout << "false" << std::endl;
    
    std::cout <<"Distance P1 to P2: " << p1.distance(p2) <<endl <<"Distance P2 to P1: " << p2.distance(p1) <<endl<< std::endl;
    
    std::cout <<"P1 x:"<< p1.getPointx()<< " " <<"P1 y:"<< p1.getPointy()<< " "   <<"P1 z:"<< p1.getPointz()<<std::endl;
    std::cout <<"P2 x:"<< p2.getPointx()<< " " <<"P2 y:"<< p2.getPointy()<< " "   <<"P2 z:"<< p2.getPointz()<<std::endl;
    //
*/
/*
    // PointCloud
    PointCloud pc1(4,0);
    PointCloud pc2(4,0);
    pc1.addPoint(5,5,5);
    pc1.addPoint(6,5,5);
    pc1.addPoint(7,5,5);
    pc1.addPoint(8,5,5);
    pc2.addPoint(5,5,5);
    pc2.addPoint(6,5,5);
    pc2.addPoint(7,5,5);
    pc2.addPoint(8,5,5);
    PointCloud pc3(4,0);
    //pc3=pc1+pc2;
    cout<<"PC::getPoint()->getPointx()"<<pc3.getPoint(0)->getPointx()<<pc3.getPoint(1)->getPointx()<<pc3.getPoint(2)->getPointx()<<pc3.getPoint(3)->getPointx();
*/
    //trans 
    cout<<endl;
    double tr[3],an[3],rot[3][3];
    tr[0]=1.95704;
    tr[1]=1.93000;
    tr[2]=1.05707;
    an[0]= -1.5577883614;
    an[1]=0.78465105723;
    an[2]=3.1324048425;
    rot[0][0]= -0.7076050;
    rot[0][1]= 0.7066082;
    rot[0][2]= 0.0000008;
    rot[1][0]= 0.0065031;
    rot[1][1]= 0.0065134;
    rot[1][2]= -0.9999576;
    rot[2][0]= -0.7065783;
    rot[2][1]= -0.7075750;
    rot[2][2]= -0.0092041;
    /* 
    // trans point with angel
    Transform transang(an,tr);    
    Point realp(8,9,2);
    Point transp(0,0,0);
    transang.setRotation(transang.getangels());
    transang.setTranslation(transang.gettrans());
    transp=transang.doTransform(realp);
    std::cout <<"realp x:"<< realp.getPointx()<< " " <<"realp y:"<< realp.getPointy()<< " "   <<"realp z:"<< realp.getPointz()<<std::endl;
    std::cout <<"transp x:"<< transp.getPointx()<< " " <<"transp y:"<< transp.getPointy()<< " "   <<"transp z:"<< transp.getPointz()<<std::endl;
    */

     /*
    // trans point with rot
    Transform transang(tr,rot);    
    Point realp(8,9,2);
    Point transp(0,0,0);
    transang.setTranslation(transang.gettrans());
    transp=transang.doTransform(realp);
    std::cout <<"realp x:"<< realp.getPointx()<< " " <<"realp y:"<< realp.getPointy()<< " "   <<"realp z:"<< realp.getPointz()<<std::endl;
    std::cout <<"transp x:"<< transp.getPointx()<< " " <<"transp y:"<< transp.getPointy()<< " "   <<"transp z:"<< transp.getPointz()<<std::endl;
    */

    /*
    // trans pointcloud with angel
    PointCloud cam(11,0);
    cam.addPoint(8,9,2);
    cam.addPoint(6,5,5);
    cam.addPoint(7,5,5);
    cam.addPoint(8,5,5);
    cam.addPoint(9,5,5);
    cam.addPoint(10,5,5);
    cam.addPoint(11,5,5);
    cam.addPoint(12,5,5);
    cam.addPoint(1,2,6);
    cam.addPoint(1,6,9);
    cam.addPoint(1,3,8);
for (int i = 0; i < cam.getPointNumber(); i++)
    {
        std::cout <<"cam :"<<i<<endl;
        std::cout <<"cam x:"<< cam.getPoint(i)->getPointx()<< " " <<"cam y:"<< cam.getPoint(i)->getPointy()<< " "   <<"cam z:"<< cam.getPoint(i)->getPointz()<<std::endl;
    }
    
    Transform transang(an,tr);
    transang.setangels(an);
    transang.settrans(tr);
    transang.setRotation(transang.getangels());
    transang.setTranslation(transang.gettrans());
    PointCloud camt(transang.doTransform(cam));
    for (int i = 0; i < camt.getPointNumber(); i++)
    {
        std::cout <<"camt :"<<i<<endl;
        std::cout <<"camt x:"<< camt.getPoint(i)->getPointx()<< " " <<"camt y:"<< camt.getPoint(i)->getPointy()<< " "   <<"camt z:"<< camt.getPoint(i)->getPointz()<<std::endl;
    }
    */
   
    /*
    // trans pointcloud with rot
    PointCloud cam(11,0);
    cam.addPoint(8,9,2);
    cam.addPoint(6,5,5);
    cam.addPoint(7,5,5);
    cam.addPoint(8,5,5);
    cam.addPoint(9,5,5);
    cam.addPoint(10,5,5);
    cam.addPoint(11,5,5);
    cam.addPoint(12,5,5);
    cam.addPoint(1,2,6);
    cam.addPoint(1,6,9);
    cam.addPoint(1,3,8);
for (int i = 0; i < cam.getPointNumber(); i++)
    {
        std::cout <<"cam :"<<i<<endl;
        std::cout <<"cam x:"<< cam.getPoint(i)->getPointx()<< " " <<"cam y:"<< cam.getPoint(i)->getPointy()<< " "   <<"cam z:"<< cam.getPoint(i)->getPointz()<<std::endl;
    }
    
    Transform transang(tr,rot);
    transang.setTranslation(transang.gettrans());
    PointCloud camt(transang.doTransform(cam));
    for (int i = 0; i < camt.getPointNumber(); i++)
    {
        std::cout <<"camt :"<<i<<endl;
        std::cout <<"camt x:"<< camt.getPoint(i)->getPointx()<< " " <<"camt y:"<< camt.getPoint(i)->getPointy()<< " "   <<"camt z:"<< camt.getPoint(i)->getPointz()<<std::endl;
    }
    */
    
    
    //
   return 0;
}