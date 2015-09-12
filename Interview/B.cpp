#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> cube;

double getEdgeLength(int left, int right) {

    double res = 0.0;
    double volume = 1.0;
    double len = right -left + 1;
    for(int i = left; i <= right; i++) {
        volume *= pow((double)cube[i], (double)(1.0 / len));
    }
    return volume;
}

int main()
{
	freopen("B-small-attempt5.in","r",stdin);
	freopen("output5.in","w",stdout);
	int caseNum;
	cin>>caseNum;
	for(int i=0;i<caseNum;++i)
	{
		cout<<"Case #"<<i+1<<":"<<endl;
		int dim;
		int queries;
		cin>>dim;
		cin>>queries;
	//	cout<< dim << " "<< queries << endl;
		if(dim >= 0) {
			for(int i = 0; i < dim; i++) {
				int temp;
				if(cin>>temp) {
					cube.push_back(temp);
	//				cout << temp << " ";
				}
			}
		}
		if(queries >= 0) {
			for(int i = 0; i < queries; i++) {
				int left;
				int right;
				cin>>left;
				cin>>right;
		//		cout << endl << left <<" "<< right <<endl;
				double res = getEdgeLength(left, right);
				cout <<fixed << setprecision(9) << res << endl; 
			}
		}
		cube.clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}