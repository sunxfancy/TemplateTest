/* 
* @Author: sxf
* @Date:   2015-03-08 08:07:45
* @Last Modified by:   sxf
* @Last Modified time: 2015-03-08 10:03:06
*/

template<class T>
class CObject
{
public:
	CObject(T k) {obj = k;}
	~CObject() {}
	T getObj();
private:
	T obj;
};