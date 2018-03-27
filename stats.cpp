#include "stats.h"
#include <cmath>


//vector< vector< long >> sumRed;
//vector< vector< long >> sumGreen;
//vector< vector< long >> sumBlue;
//vector< vector< long >> sumsqRed;
//vector< vector< long >> sumsqGreen;
//vector< vector< long >> sumsqBlue;


/* returns the sums of all pixel values across the color channel.
* useful in computing the score of a rectangle
* PA3 function
* @param channel is one of r, g, or b
* @param ul is (x,y) of the upper left corner of the rectangle 
* @param lr is (x,y) of the lower right corner of the rectangle */
long stats::getSum(char channel, pair<int,int> ul, pair<int,int> lr){
    vector< vector< long >> colour;
    long sum = 0;
    if (channel == 'r'){
        sum = sumRed[lr.first][lr.second];
    }
    else if (channel == 'g'){
        sum = sumGreen[ul.second][lr.second];
    }
    else if (channel == 'b'){
        sum = sumBlue[ul.second][lr.second];
    }
	return sum;
}
/* returns the sums of squares of all pixel values across the color channel.
* useful in computing the score of a rectangle
* PA3 function
* @param channel is one of r, g, or b
* @param ul is (x,y) of the upper left corner of the rectangle 
* @param lr is (x,y) of the lower right corner of the rectangle */
long stats::getSumSq(char channel, pair<int,int> ul, pair<int,int> lr){
    vector< vector< long >> colour;
    long sum = 0;
    if (channel == 'r'){
        sum = sumsqRed[lr.first][lr.second];
    }
    else if (channel == 'g'){
        sum = sumsqGreen[ul.second][lr.second];
    }
    else if (channel == 'b'){
        sum = sumsqBlue[ul.second][lr.second];
    }
    return sum;

    
}



// initialize the private vectors so that, for each color,  entry 
// (x,y) is the cumulative sum of the the color values from (0,0)
// to (x,y). Similarly, the sumSq vectors are the cumulative
// sum of squares from (0,0) to (x,y).
stats::stats(PNG & im){
    long redSum   = 0;
    long greenSum = 0;
    long blueSum  = 0;

    long redSqSum   = 0;
    long greenSqSum = 0;
    long blueSqSum  = 0;

	for (int x = 0 ; x < (int) im.width(); ++x){

        vector<long> redVectorOne;
        vector<long> greenVectorOne;
        vector<long> blueVectorOne;

        vector<long> redVectorOneSq;
        vector<long> greenVectorOneSq;
        vector<long> blueVectorOneSq;

        

		for (int y = 0; y < (int) im.height(); ++y){
			RGBAPixel* temp = im.getPixel(x, y);

            if ((x+y == 0))
            {
                redVectorOne.push_back(temp->r);
            }
            else if (x < 1)
            {
                //RGBAPixel* temp1 = im.getPixel(x, y-1);
                redVectorOne.push_back(redVectorOne[y-1]+temp->r);
            }
            else
            {
                if (y == 0)
                {
                    int sumRR = temp->r + sumRed[x-1][y];
                    redVectorOne.push_back(sumRR);
                }
                else
                {
                    int sumR = 0;
                    sumR= sumRed[x-1][y] + redVectorOne[y-1] + temp->r - sumRed[x-1][y-1];
                    redVectorOne.push_back(sumR);
                }
                
            }
            // redSum += temp->r;
            // greenSum += temp->g;
            // blueSum += temp->b;

            // redSqSum += (temp->r)^2;
            // greenSqSum += (temp->g)^2;
            // blueSqSum += (temp->b)^2;

            // redVectorOne.push_back(redSum);
            // greenVectorOne.push_back(greenSum);
            // blueVectorOne.push_back(blueSum);

            // redVectorOneSq.push_back(redSqSum);
            // greenVectorOneSq.push_back(greenSqSum);
            // blueVectorOneSq.push_back(blueSqSum);

		}
        sumRed.push_back(redVectorOne);
        // sumGreen.push_back(greenVectorOne);
        // sumBlue.push_back(blueVectorOne);

        // sumsqRed.push_back(redVectorOneSq);
        // sumsqGreen.push_back(greenVectorOneSq);
        // sumsqBlue.push_back(blueVectorOneSq);

	}

} 


// given a rectangle, compute its sum of squared deviations from 
// mean, over all color channels. Will be used to make split when
// building tree.
/* @param ul is (x,y) of the upper left corner of the rectangle 
* @param lr is (x,y) of the lower right corner of the rectangle */
long stats::getScore(pair<int,int> ul, pair<int,int> lr){
	//Σx2−(Σx)2|R|
	//RGBAPixel pixelAvg = getAvg(ul, lr);
	long score = getSumSq('r', ul, lr) - (getSum('r', ul, lr)^2/rectArea(ul, lr)) +
	             getSumSq('g', ul, lr) - (getSum('g', ul, lr)^2/rectArea(ul, lr)) + 
	             getSumSq('b', ul, lr) - (getSum('b', ul, lr)^2/rectArea(ul, lr));
	return score;

}

// given a rectangle, return the average color value over the 
// rectangle as a pixel.
/* Each color component of the pixel is the average value of that 
* component over the rectangle.
* @param ul is (x,y) of the upper left corner of the rectangle 
* @param lr is (x,y) of the lower right corner of the rectangle */
RGBAPixel stats::getAvg(pair<int,int> ul, pair<int,int> lr){
	int pixelCount = rectArea(ul, lr);
	long redAvg = getSum('r', ul, lr)/pixelCount;
	long greenAvg = getSum('g', ul, lr)/pixelCount;
	long blueAvg = getSum('b', ul, lr)/pixelCount;
	RGBAPixel pixelAvg = RGBAPixel(redAvg, greenAvg, blueAvg);
	return pixelAvg;

}

// given a rectangle, return the number of pixels in the rectangle
/* @param ul is (x,y) of the upper left corner of the rectangle 
* @param lr is (x,y) of the lower right corner of the rectangle */
long stats::rectArea(pair<int,int> ul, pair<int,int> lr){
	return (lr.first - ul.first)*(lr.second - ul.second);

}

