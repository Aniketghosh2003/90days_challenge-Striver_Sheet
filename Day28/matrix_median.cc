#include <bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix) {  

    int matrixMin = INT_MAX;
    int matrixMax = INT_MIN;

    int numRows = matrix.size();
    int numCols = matrix[0].size();

 
    for (int i = 0; i < numRows; i++) {

        matrixMax = max(matrixMax, matrix[i][numCols - 1]);
        matrixMin = min(matrixMin, matrix[i][0]);

    }

    int left = matrixMin;
    int right = matrixMax;

    while (left < right) {

        int mid = left + (right - left) / 2;

 

        int greaterCount = 0;

        int smallerCount = 0;

        int equalCount = 0;  

        for (int i = 0; i < numRows; i++) {

            for (int j = 0; j < numCols; j++) {

                if (matrix[i][j] > mid) {

                    greaterCount++;

                } else if (matrix[i][j] < mid) {

                    smallerCount++;

                } else {

                    equalCount++;

                }

            }

        }

        if (greaterCount > smallerCount && greaterCount - smallerCount > equalCount) {

            left = mid + 1;

        } else if (greaterCount < smallerCount && smallerCount - greaterCount > equalCount) {

            right = mid - 1;

        } else {

            return mid;

        }

    }

 

    return left;
}