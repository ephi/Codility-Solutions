//see the challange at: https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
//complexity: assume the number of elements in S is N
//runtime complexity: O(N)
//space complexity: O(1)
//the main idea in resolving this with O(1) space complexity is to uderstand that if we "predict" a closing bracket
//then we already has to close all instances of the same kind, and also to make sure the previous bracket wasnt an opening of a diffrent kind
int solution(string  S) {
    int N = S.size();
    if(N == 0) return 1;//empty string is properly nested
    if(S[0] == ')' || S[0] == ']' || S[0] == '}' ) return 0;// a propery nested string cannot beging with //those chars
    if(S[N-1] == '(' || S[N-1] == '[' || S[N-1] == '{' ) return 0; // cannot end with those chars
    int paren_open = 0;
    int brac_open = 0;
    int curl_open = 0;
    for(int i =0 ; i < N;++i){
       if(S[i] == ')' && (paren_open == 0 || S[i-1] == '[' || S[i-1] == '{')) return 0; //expected opening but got closing
       if(S[i] == ']' && (brac_open == 0 || S[i-1] == '(' || S[i-1] == '{')) return 0; //same here
       if(S[i] == '}' && (curl_open == 0 || S[i-1] == '[' || S[i-1] == '(')) return 0; //same here
       if(S[i] == '(') paren_open++;
       else if(S[i] == ')') paren_open--;
       else if(S[i] == '[') brac_open++;
       else if(S[i] == ']') brac_open--;
       else if(S[i] == '{') curl_open++;
       else if(S[i] == '}') curl_open--;
    }
    if(paren_open == 0 && brac_open == 0 && curl_open ==0)
       return 1;
    return 0;
}
