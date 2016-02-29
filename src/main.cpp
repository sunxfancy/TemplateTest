/* 
* @Author: sxf
* @Date:   2015-03-08 08:07:06
* @Last Modified by:   sxf
* @Last Modified time: 2015-03-08 09:57:50
*/

#include <cstdio>
#include "CObject.h"

using namespace std;

int main(){
	CObject<int> Obj(10);
	int k = Obj.getObj();
	printf("%d\n", k);
    return 0;
}
