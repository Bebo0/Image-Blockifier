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
        if (ul.first == 0 && ul.second == 0)
        {
            sum = sumRed[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0)
        {
            sum = sumRed[lr.first][lr.second] - sumRed[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0)
        {
            sum = sumRed[lr.first][lr.second] - sumRed[lr.first][ul.second-1];
        }
        else
        {
            sum = sumRed[lr.first][lr.second] - sumRed[lr.first][ul.second-1] - 
            sumRed[ul.first-1][lr.second] + sumRed[ul.first-1][ul.second-1];
        }
        
    }
    else if (channel == 'g'){
        if (ul.first == 0 && ul.second == 0)
        {
            sum = sumGreen[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0)
        {
            sum = sumGreen[lr.first][lr.second] - sumGreen[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0)
        {
            sum = sumGreen[lr.first][lr.second] - sumGreen[lr.first][ul.second-1];
        }
        else
        {
            sum = sumGreen[lr.first][lr.second] - sumGreen[lr.first][ul.second-1] - 
            sumGreen[ul.first-1][lr.second] + sumGreen[ul.first-1][ul.second-1];
        }
        
    }
    else if (channel == 'b'){
        if (ul.first == 0 && ul.second == 0)
        {
            sum = sumBlue[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0)
        {
            sum = sumBlue[lr.first][lr.second] - sumBlue[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0)
        {
            sum = sumBlue[lr.first][lr.second] - sumBlue[lr.first][ul.second-1];
        }
        else
        {
            sum = sumBlue[lr.first][lr.second] - sumBlue[lr.first][ul.second-1] - 
            sumBlue[ul.first-1][lr.second] + sumBlue[ul.first-1][ul.second-1];
        }
        
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
        if (ul.first == 0 && ul.second == 0)
        {
            sum = sumsqRed[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0)
        {
            sum = sumsqRed[lr.first][lr.second] - sumsqRed[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0)
        {
            sum = sumsqRed[lr.first][lr.second] - sumsqRed[lr.first][ul.second-1];
        }
        else
        {
            sum = sumsqRed[lr.first][lr.second] - sumsqRed[lr.first][ul.second-1] - 
            sumsqRed[ul.first-1][lr.second] + sumsqRed[ul.first-1][ul.second-1];
        }
        
    }
    else if (channel == 'g'){
        if (ul.first == 0 && ul.second == 0)
        {
            sum = sumsqGreen[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0)
        {
            sum = sumsqGreen[lr.first][lr.second] - sumsqGreen[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0)
        {
            sum = sumsqGreen[lr.first][lr.second] - sumsqGreen[lr.first][ul.second-1];
        }
        else
        {
            sum = sumsqGreen[lr.first][lr.second] - sumsqGreen[lr.first][ul.second-1] - 
            sumsqGreen[ul.first-1][lr.second] + sumsqGreen[ul.first-1][ul.second-1];
        }
        
    }
    else if (channel == 'b'){
        if (ul.first == 0 && ul.second == 0)
        {
            sum = sumsqBlue[lr.first][lr.second];
        }
        else if (ul.first > 0 && ul.second == 0)
        {
            sum = sumsqBlue[lr.first][lr.second] - sumsqBlue[ul.first-1][lr.second];
        }
        else if (ul.first == 0 && ul.second > 0)
        {
            sum = sumsqBlue[lr.first][lr.second] - sumsqBlue[lr.first][ul.second-1];
        }
        else
        {
            sum = sumsqBlue[lr.first][lr.second] - sumsqBlue[lr.first][ul.second-1] - 
            sumsqBlue[ul.first-1][lr.second] + sumsqBlue[ul.first-1][ul.second-1];
        }
        
    }
    return sum;

    
}

void stats::printValues()
{
    //printf("%li\n",   sumRed[0][i]);
    for (int x = 0; x < (int) sumsqGreen.size(); ++x)
    {
        for (int y = 0; y < (int) sumsqGreen.size(); ++y)
        {
            printf("%li   ", sumsqGreen[x][y]);
        }
        printf("\n");
    }
}

// initialize the private vectors so that, for each color,  entry 
// (x,y) is the cumulative sum of the the color values from (0,0)
// to (x,y). Similarly, the sumSq vectors are the cumulative
// sum of squares from (0,0) to (x,y).
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

            int sumRR = 0;
            int sumGG = 0;
            int sumBB = 0;

            int sumRRsq = 0;
            int sumGGsq = 0;
            int sumBBsq = 0;

            if ((x+y == 0))
            {
                redVectorOne.push_back(temp->r);
                greenVectorOne.push_back(temp->g);
                blueVectorOne.push_back(temp->b);

                redVectorOneSq.push_back((temp->r*temp->r));
                greenVectorOneSq.push_back((temp->g*temp->g));
                blueVectorOneSq.push_back((temp->b*temp->b));

                // printf("%i x+y \n ", sumGGsq);
            }
            else if (x < 1)
            {
                //RGBAPixel* temp1 = im.getPixel(x, y-1);
                redVectorOne.push_back(redVectorOne[y-1]+temp->r);
                greenVectorOne.push_back(greenVectorOne[y-1]+temp->g);
                blueVectorOne.push_back(blueVectorOne[y-1]+temp->b);

                redVectorOneSq.push_back(redVectorOneSq[y-1]+(temp->r*temp->r));
                greenVectorOneSq.push_back(greenVectorOneSq[y-1]+(temp->g*temp->g));
                blueVectorOneSq.push_back(blueVectorOneSq[y-1]+(temp->b*temp->b));

                // printf("%i x<1 \n ", sumGGsq);
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

                    // printf("%i y==0 \n ", temp->g);
                    // printf("%i temp->g^2 \n ", temp->g^2);
                    // printf("%li is this zero? \n ", sumsqGreen[x-1][y]);
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

                    // printf("%i else\n  ", sumGGsq);
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

