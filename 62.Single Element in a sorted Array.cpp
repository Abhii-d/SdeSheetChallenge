/*Problem Statement
Nobita wants to impress Shizuka by guessing her lucky number.
Shizuka gave Nobita a sorted list of ‘N’ numbers such that every number occurred twice in the list except Shizuka’s lucky number which appears only once.
Nobita asked Doraemon to help him but Doraemon doesn’t have a gadget that can find Shizuka’s lucky number.
So, Doraemon called you to find Shizuka’s lucky number. The fate of Nobita lies in your hand.*/




int uniqueElement(vector<int> arr, int n)
{
    int  res = 0;
    for(int i=0 ;i < n; i++ ){
        res=res^ arr[i];
    }
    return res;
}
