#include <iostream>
#include <string>
using namespace std;

int mystery(int u, int &v) {
    u *= 2;
    v ++ ;
    return u + v;
} // mystery(int, int)

int main() {
  // int alpha = 68;
  // double beta=3.75;
  // string comment;
  // if (alpha > 75 && beta > 3.6)
  //   comment = "full scholarship";
  // else if (alpha > 70 && beta > 3.2)
  //   comment= "3/4 scholarship";
  // else if (alpha > 65 && beta > 3.0)
  //   comment = "half scholarship";
  // else
  //   comment = "no scholarship";
  // cout << comment << endl;
  //
  // int result = 1;
  // for (int i = - 2;  i <5;  i+=2)   result += i;
  // cout << result << endl;
  //
  // struct ShoeType {
  //   string style;
  //   double price;
  // };
  // ShoeType shoe1, *pshoe2;
  //
  // shoe1.style = "Adidas";  shoe1.price = 9.99;
  // pshoe2 = &shoe1;
  // pshoe2->price = pshoe2->price / 9;
  // cout << shoe1.style << " $ "<< shoe1.price;
  // cout << pshoe2->style << " $ "<< pshoe2->price;
  // return 0;

  // char ch = 'b';
  // switch (ch) {
  //   case 'a': cout <<"I "; break;
  //   case 'b':
  //   case 'B': cout << "Love ";
  //   case 'c': cout<< "Nemo"; break;
  //   default: cout << "Terribly"; break;

  // int audra = 7;
  // int molley = 10;
  // mystery(audra, molley);
  // cout << "audra=" << audra << "molley=" << molley << endl;

  // int arr[4] = {4, 5, 6, 7};
  // int *p = (arr + 1);
  // cout << *p;
  // return 0;


  // int matrix[4][3];
  // int j, k;
  // for (j = 0; j < 4; j++)
	//  for (k = 0; k < 3; k++)
	// 	  matrix[j][k] = 2 * j + k;
  //
  // for(int i = 0; i < 4; i++) {
  //   for(int l = 0; l < 3; l++) {
  //     cout << matrix[i][l] << " ";
  //   }
  //   cout << endl;
  // }


}
