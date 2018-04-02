
// File:        main.cpp
// Author:      cheeren
// Date:        2018-02-25
// Description: Partial test of PA3 functionality
//              Reads Point data from external files
//              Produces PNG images of the point sets


#include "twoDtree.h"
#include "cs221util/RGBAPixel.h"
#include "cs221util/PNG.h"

using namespace cs221util;
using namespace std;

int main()
{

	// read in image
	PNG origImTest;
	origImTest.readFromFile("images/stanley-totem-poles.png");
	PNG origIm1;
	origIm1.readFromFile("images/stanley-totem-poles.png");
	// PNG origIm2;
	// origIm2.readFromFile("images/ubc-totem-poles.png");
	// PNG origIm3;
	// origIm3.readFromFile("images/remb.png");
	// PNG origIm4;
	// origIm4.readFromFile("images/rosa.png");

	//stats s = stats(origImTest);
	// std::pair <int,int> foo;
 //  	std::pair <int,int> bar;
 
 //  	foo = std::make_pair (0,0);
 //  	bar = std::make_pair (origImTest.width()-1 ,origImTest.height()-1 );

 //  	cout<<"WIDTH:  "<<origImTest.width() <<endl;
 //  	cout<<"WIDTH:  "<<origImTest.height() <<endl;
  	//printf("%u\n", origImTest.width());


	//pair <int,int> ul = make_pair <0, 0>;
	//pair <int,int> lr = make_pair <origIm1.width(), origIm1.height()>;

	//stats s = stats(origImTest);
	// printf("%li\n", s.getSum('r', foo, bar ));
	// printf("%li\n", s.getSum('g', foo, bar ));
	// printf("%li\n", s.getSum('b', foo, bar ));


	// printf("%hhu\n", s.getAvg(foo, bar ).r);
	// printf("%li\n", s.getScore(foo, bar ));
	// printf("%li\n", s.rectArea(foo, bar ));



	// stats s = stats(origIm1);
 //    for (int x=0; x< (int) origIm1.width();x++){
 //        for (int y=0;y< (int)  origIm1.height();y++){
 //        cout<< x <<","<<y<<"  :" << s.sumRed[x][y]<<"   ";
 //            pair<int,int> p1 = {x,y};
 //            pair<int,int> ori = {0,0};
 //            cout<<"pixel: "<< s.getSum('r',p1,p1)<<endl;
            
 //            cout<<"get score:  "<<s.getScore(p1,p1) <<endl;
            
 //            cout<<"get scorefrom original:  "<<s.getScore(ori,p1) <<endl;
 //            cout<<endl;
            
 //        }
 //    }

	//printf("%li\n", s.getSumSq('r', foo, bar ));
	//printf("%li\n", s.getSumSq('g', foo, bar ));
	//printf("%li\n", s.getSumSq('b', foo, bar ));
	//
	// //
	//s.printValues();



	// // use it to build a twoDtree
	
	twoDtree t0(origImTest);
	twoDtree tCopy0(t0);

	//twoDtree t1(origIm1);
	//twoDtree tCopy1(t1);
	// twoDtree t2(origIm2);
	// twoDtree tCopy2(t2);
	// twoDtree t3(origIm3);
	// twoDtree tCopy3(t3);
	// twoDtree t4(origIm4);
	// twoDtree tCopy4(t4);

	// // prune the twoDtree
	//where at least 100*X% of pixels are within Y of mean
	// tCopy1.prune(0.95, 10000); 
	// tCopy2.prune(0.95, 10000); 
	// tCopy3.prune(0.95, 3000); 
	// tCopy4.prune(0.95, 3000); 
	PNG ppic0 = tCopy0.render();
	// // render the twoDtree
	//PNG ppic1 = tCopy1.render();
	// // PNG ppic2 = tCopy2.render();
	// // PNG ppic3 = tCopy3.render();
	// // PNG ppic4 = tCopy4.render();
	ppic0.writeToFile("images/testoutput.png");

	//ppic1.writeToFile("images/prunedstanleytotem.png");
	// ppic2.writeToFile("images/prunedubctotem.png");
	// ppic3.writeToFile("images/prunedremb.png");
	// ppic4.writeToFile("images/prunedrosa.png");

  return 0;
}

