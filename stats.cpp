#include "stats.h"

#include <utility>
#include "cs221util/PNG.h"
#include "cs221util/RGBAPixel.h"
#include <numeric>

using namespace std;
using namespace cs221util;


	/* returns the sums of all pixel values across the given color channels.
	* useful in computing the score of a rectangle
	* PA3 function
	* @param channel is one of r, g, or b
	* @param ul is (x,y) of the upper left corner of the rectangle
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::getSum(char channel, pair<int,int> ul, pair<int,int> lr){
    //std::cout<< "start of getsum"<<endl;
    vector< vector< long >> colour;
    long sum = 0;
    if (channel == 'r'){
        if (ul.first == 0 && ul.second == 0){
            sum = sumRed[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0){
            sum = sumRed[lr.first][lr.second] - sumRed[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0){
            sum = sumRed[lr.first][lr.second] - sumRed[lr.first][ul.second-1];
        }
        else{
            sum = sumRed[lr.first][lr.second] - sumRed[lr.first][ul.second-1] - 
            sumRed[ul.first-1][lr.second] + sumRed[ul.first-1][ul.second-1];
        }
        
    }
    else if (channel == 'g'){
        if (ul.first == 0 && ul.second == 0){
            sum = sumGreen[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0){
            sum = sumGreen[lr.first][lr.second] - sumGreen[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0){
            sum = sumGreen[lr.first][lr.second] - sumGreen[lr.first][ul.second-1];
        }
        else{
            sum = sumGreen[lr.first][lr.second] - sumGreen[lr.first][ul.second-1] - 
            sumGreen[ul.first-1][lr.second] + sumGreen[ul.first-1][ul.second-1];
        }
        
    }
    else if (channel == 'b'){
        if (ul.first == 0 && ul.second == 0){
            sum = sumBlue[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0){
            sum = sumBlue[lr.first][lr.second] - sumBlue[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0){
            sum = sumBlue[lr.first][lr.second] - sumBlue[lr.first][ul.second-1];
        }
        else{
            sum = sumBlue[lr.first][lr.second] - sumBlue[lr.first][ul.second-1] - 
            sumBlue[ul.first-1][lr.second] + sumBlue[ul.first-1][ul.second-1];
        }
        
    }
    //std::cout<< "end of getsum"<<endl;
    return sum;
}
/* returns the sums of squares of all pixel values across the color channel.
* useful in computing the score of a rectangle
* PA3 function
* @param channel is one of r, g, or b
* @param ul is (x,y) of the upper left corner of the rectangle 
* @param lr is (x,y) of the lower right corner of the rectangle */
long stats::getSumSq(char channel, pair<int,int> ul, pair<int,int> lr){
    //std::cout<< "start of getsumsq"<<endl;
    //vector< vector< long >> colour;
    long sum = 0;
    if (channel == 'r'){
        if (ul.first == 0 && ul.second == 0){
            sum = sumsqRed[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0){
            sum = sumsqRed[lr.first][lr.second] - sumsqRed[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0){
            sum = sumsqRed[lr.first][lr.second] - sumsqRed[lr.first][ul.second-1];
        }
        else{
            sum = sumsqRed[lr.first][lr.second] - sumsqRed[lr.first][ul.second-1] - 
            sumsqRed[ul.first-1][lr.second] + sumsqRed[ul.first-1][ul.second-1];
        }
        
    }
    else if (channel == 'g'){
        if (ul.first == 0 && ul.second == 0){
            sum = sumsqGreen[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0){
            sum = sumsqGreen[lr.first][lr.second] - sumsqGreen[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0){
            sum = sumsqGreen[lr.first][lr.second] - sumsqGreen[lr.first][ul.second-1];
        }
        else{
            sum = sumsqGreen[lr.first][lr.second] - sumsqGreen[lr.first][ul.second-1] - 
            sumsqGreen[ul.first-1][lr.second] + sumsqGreen[ul.first-1][ul.second-1];
        }
        
    }
    else if (channel == 'b'){
        if (ul.first == 0 && ul.second == 0){
            sum = sumsqBlue[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0){
            sum = sumsqBlue[lr.first][lr.second] - sumsqBlue[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0){
            sum = sumsqBlue[lr.first][lr.second] - sumsqBlue[lr.first][ul.second-1];
        }
        else{
            sum = sumsqBlue[lr.first][lr.second] - sumsqBlue[lr.first][ul.second-1] - 
            sumsqBlue[ul.first-1][lr.second] + sumsqBlue[ul.first-1][ul.second-1];
        }
        
    }

    //std::cout<< "end of getsumsq"<<endl;
    return sum;

    
}

  stats::stats(PNG & im){
   

	for (int x = 0 ; x < (int) im.width(); ++x){

        vector<long> redVectorOne;
        vector<long> greenVectorOne;
        vector<long> blueVectorOne;

        vector<long> redVectorOneSq;
        vector<long> greenVectorOneSq;
        vector<long> blueVectorOneSq;

        

		for (int y = 0; y < (int) im.height(); ++y){
			RGBAPixel* temp = im.getPixel(x, y);

            long sumRR = 0;
            long sumGG = 0;
            long sumBB = 0;

            long sumRRsq = 0;
            long sumGGsq = 0;
            long sumBBsq = 0;

            if ((x+y == 0))
            {
                redVectorOne.push_back(temp->r);
                greenVectorOne.push_back(temp->g);
                blueVectorOne.push_back(temp->b);

                redVectorOneSq.push_back((temp->r*temp->r));
                greenVectorOneSq.push_back((temp->g*temp->g));
                blueVectorOneSq.push_back((temp->b*temp->b));

              
            }
            else if (x < 1)
            {
     
                redVectorOne.push_back(redVectorOne[y-1]+temp->r);
                greenVectorOne.push_back(greenVectorOne[y-1]+temp->g);
                blueVectorOne.push_back(blueVectorOne[y-1]+temp->b);

                redVectorOneSq.push_back(redVectorOneSq[y-1]+(temp->r*temp->r));
                greenVectorOneSq.push_back(greenVectorOneSq[y-1]+(temp->g*temp->g));
                blueVectorOneSq.push_back(blueVectorOneSq[y-1]+(temp->b*temp->b));

               
            }
            else
            {
                if (y == 0)
                {
                    sumRR = temp->r + sumRed[x-1][y];
                    redVectorOne.push_back(sumRR);
                    sumGG = temp->g + sumGreen[x-1][y];
                    greenVectorOne.push_back(sumGG);
                    sumBB = temp->b + sumBlue[x-1][y];
                    blueVectorOne.push_back(sumBB);

                    sumRRsq = (temp->r*temp->r) + sumsqRed[x-1][y];
                    redVectorOneSq.push_back(sumRRsq);
                    sumGGsq = (temp->g*temp->g) + sumsqGreen[x-1][y];
                    greenVectorOneSq.push_back(sumGGsq);
                    sumBBsq = (temp->b*temp->b) + sumsqBlue[x-1][y];
                    blueVectorOneSq.push_back(sumBBsq);

                
                }
                else
                {
                 
                    sumRR= sumRed[x-1][y] + redVectorOne[y-1] + temp->r - sumRed[x-1][y-1];
                    redVectorOne.push_back(sumRR);
                    sumGG= sumGreen[x-1][y] + greenVectorOne[y-1] + temp->g - sumGreen[x-1][y-1];
                    greenVectorOne.push_back(sumGG);
                    sumBB= sumBlue[x-1][y] + blueVectorOne[y-1] + temp->b - sumBlue[x-1][y-1];
                    blueVectorOne.push_back(sumBB);

                    sumRRsq= sumsqRed[x-1][y] + redVectorOneSq[y-1] + (temp->r*temp->r) - sumsqRed[x-1][y-1];
                    redVectorOneSq.push_back(sumRRsq);
                    sumGGsq= sumsqGreen[x-1][y] + greenVectorOneSq[y-1] + (temp->g*temp->g) - sumsqGreen[x-1][y-1];
                    greenVectorOneSq.push_back(sumGGsq);
                    sumBBsq= sumsqBlue[x-1][y] + blueVectorOneSq[y-1] + (temp->b*temp->b) - sumsqBlue[x-1][y-1];
                    blueVectorOneSq.push_back(sumBBsq);

                }
                
            }
          

		}
        sumRed.push_back(redVectorOne);
        sumGreen.push_back(greenVectorOne);
        sumBlue.push_back(blueVectorOne);

        sumsqRed.push_back(redVectorOneSq);
        sumsqGreen.push_back(greenVectorOneSq);
        sumsqBlue.push_back(blueVectorOneSq);

	}

} 



  // given a rectangle, compute its sum of squared deviations from
        // mean, over all color channels. Will be used to make split when
  // building tree.
  /* @param ul is (x,y) of the upper left corner of the rectangle
  * @param lr is (x,y) of the lower right corner of the rectangle */
  long stats::getScore(pair<int,int> ul, pair<int,int> lr){
		long deviationRed = getSumSq('r',ul,lr)- (getSum('r',ul,lr)*getSum('r',ul,lr))/(double)rectArea(ul,lr);
		long deviationGreen = getSumSq('g',ul,lr)- (getSum('g',ul,lr)*getSum('g',ul,lr))/(double)rectArea(ul,lr);
		long deviationBlue = getSumSq('b',ul,lr)- (getSum('b',ul,lr)*getSum('b',ul,lr))/(double)rectArea(ul,lr);
    return deviationRed+deviationGreen+deviationBlue;
  }

  // given a rectangle, return the average color value over the
  // rectangle as a pixel.
  /* Each color component of the pixel is the average value of that
  * component over the rectangle.
  * @param ul is (x,y) of the upper left corner of the rectangle
  * @param lr is (x,y) of the lower right corner of the rectangle */
  RGBAPixel stats::getAvg(pair<int,int> ul, pair<int,int> lr){
		int pixelCount = rectArea(ul,lr);
		long avgRed = getSum('r',ul,lr)/pixelCount;
		long avgGreen = getSum('g',ul,lr)/pixelCount;
		long avgBlue = getSum('b',ul,lr)/pixelCount;
    return RGBAPixel(avgRed,avgGreen,avgBlue);
  }

  // given a rectangle, return the number of pixels in the rectangle
  /* @param ul is (x,y) of the upper left corner of the rectangle
  * @param lr is (x,y) of the lower right corner of the rectangle */
  long stats::rectArea(pair<int,int> ul, pair<int,int> lr){
		long area=1;
		if (ul.first == lr.first && ul.second == lr.second){
			area = 1;
		}
		else if(lr.first >= ul.first && lr.second >= lr.first){
			area = (lr.first - ul.first+1)*(lr.second - ul.second +1);}
		return area;

  }
