//see the challange at: https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
//complexity: assume the number of elements in S is N
//runtime complexity: O(N)
//space complexity: O(1)
//the main idea in resolving this with O(1) space complexity is as follow:
//1) keeping track of the amount of closing and opening brackets. 
//This is done using counters to create a balance. After passing through the string once then every counter should contain 0 
//if the amount of brackets was balanced
//2) understanding how to catch structural issues without the stack. the idea here is that each iteration of the loop also "predicts"
//which bracket should appear (I address prediction as a term before the update of the counter). it is then sufficent to understand
//that if we "predict" a closing bracket of some kind(i.e: ) or ] or }) then it is impossible to have an even balance
//meaning that the counter of the matching bracket shouldn't be 0 if the structre is correct. Additonally, it is impossbile for
//the previous character to be an opening bracket of diffrent kind (witch results with miss-match type closing).
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
