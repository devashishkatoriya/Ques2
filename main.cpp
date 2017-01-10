/*
Let isSubSetSum(int set[], int n, int sum) be the function to find whether there is a
 subset of set[] with sum equal to sum. n is the number of elements in set[].

The isSubsetSum problem can be divided into two sub problems
…a) Include the last element, recur for n = n-1, sum = sum – set[n-1]
…b) Exclude the last element, recur for n = n-1.
If any of the above the above subproblems return true, then return true.

Following is the recursive formula for isSubsetSum() problem.

isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) ||
                           isSubsetSum(set, n-1, sum-set[n-1])
Base Cases:
isSubsetSum(set, n, sum) = false, if sum > 0 and n == 0
isSubsetSum(set, n, sum) = true, if sum == 0
Following is naive recursive implementation that simply follows the recursive structure mentioned above.

 */

#include <iostream>

using namespace std;

bool isSubsetSum(int set[],int n,int sum)
{
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

    // If last element is greater than sum, then ignore it
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);

    /* else, check if sum can be obtained by any of the following
       (a) including the last element
       (b) excluding the last element   */
    return isSubsetSum(set, n-1, sum) ||
           isSubsetSum(set, n-1, sum-set[n-1]);
}

void bubble_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;i++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int a[100],i,n,sum;
    cout<<"\nEnter how many elements ? ";
    cin>>n;
    cout<<"\nEnter the array :- \n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubble_sort(a,n);

    cout<<"\nEnter sum that you believe : ";
    cin>>sum;

    if(isSubsetSum(a,n,sum))
    {
        cout<<"\nYes";
    }
    else
    {
        cout<<"\nNO!";
    }

    return 0;
}