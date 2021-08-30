#include<fstream>
#include<iostream>
#include<vector>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (std::vector<int>&arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(std::vector<int>&arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    std::fstream fin;
    std::ifstream ifin;
    std::ofstream ofile;
    ifin.open("bigNum.txt");
    int num;
    int count = 0;
    std::vector<int> mArr;
    while (!ifin.eof())
    {
        num = 0;
        ifin >> num;
        count++;
        if(count >= 0 && count <= 37500000) {
            mArr.push_back(num);
        }
        if(count == 37500000) {
            quickSort(mArr,0,mArr.size());
            ofile.open("sortFile1.txt");
            for(int i = 0;i < mArr.size();i++) {
                ofile << mArr[i] << std::endl;
            }
            mArr.clear();
            ofile.close();
        }
        if(count >= 37500000 && count <= 75000000) {
            mArr.push_back(num);
        }
        if(count == 75000000) {
            quickSort(mArr,0,mArr.size());
            ofile.open("sortFile2.txt");
            for(int i = 0;i < mArr.size();i++) {
                ofile << mArr[i] << std::endl;
            }
            mArr.clear();
            ofile.close();
        }
        if(count >= 75000000 && count <= 112500000) {
            mArr.push_back(num);
        }
        if(count == 112500000) {
            quickSort(mArr,0,mArr.size());
            ofile.open("sortFile3.txt");
            for(int i = 0;i < mArr.size();i++) {
                ofile << mArr[i] << std::endl;
            }
            mArr.clear();
            ofile.close();
        }
        if(count >= 112500000 && count <= 150000000) {
            mArr.push_back(num);
        }
        if(count == 150000000) {
            quickSort(mArr,0,mArr.size());
            ofile.open("sortFile4.txt");
            for(int i = 0;i < mArr.size();i++) {
                ofile << mArr[i] << std::endl;
            }
            mArr.clear();
            ofile.close();
        }
        
    }
    
    int number = 0;
    std::ifstream a;
    a.open("sortFile1.txt");
    std::ifstream b;
    b.open("sortFile2.txt");
    std::ifstream c;
    c.open("sortFile3.txt");
    std::ifstream d;
    d.open("sortFile4.txt");
    std::ofstream ofil;
    ofil.open("extreamFile.txt");
    int arr[4];
    a >> number;
    arr[0] = number;
    b >> number;
    arr[1] = number;
    c >> number;
    arr[2] = number;
    d >> number;
    arr[3] = number;
    std::cout << arr[0];
    std::cout << arr[1];
    std::cout << arr[2];
    std::cout << arr[3];
    while (!a.eof() && !b.eof() && !c.eof() && !d.eof())
    {       
        if(arr[0] <= arr[1] && arr[0] <= arr[2] && arr[0] <= arr[3]) {
            ofil << arr[0] <<std::endl ;
            a >> arr[0];
        }
        if(arr[1] <= arr[0] && arr[1] <= arr[2] && arr[1] <= arr[3]) {
            ofil << arr[1] <<std::endl ;
            b >> arr[1];
        }
        if(arr[2] <= arr[0] && arr[2] <= arr[1] && arr[2] <= arr[3]) {
            ofil << arr[2] <<std::endl ;
            c >> arr[2];
        }
        if(arr[3] <= arr[0] && arr[3] <= arr[1] && arr[3] <= arr[2]) {
            ofil << arr[3] <<std::endl ;
            d >> arr[3];
        }

    }
    

    a.close();
    b.close();
    c.close();
    d.close();
    ofil.close();
    ifin.close();

}