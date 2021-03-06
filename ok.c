
   // PSEUDOCODE //
    // while(reading lines):
    //     strip_whitespace(line) // strip from the ends only
    //
    //     check if line starts with "\question"
    //            set in_question
    //        
    //       if in_question && line starts with {
    //            find '='
    //                set equals_index
    //            find '}'
    //                set close_index
    //
    //            in_braces = false
    //            
    //            // assign according to content in braces
    //            assign(bef_equals, after_equals)
    //
    //
    //    assign():
    //        check bef_equals
    //        call relevant function
    // assign(question, string_before, string_after)

void assign(Question_B question, char string_before[],char string_after[])
{
    // we can use toupper() to make strings independent of whether its BLOCK letters or not
    if(strcmp(string_before,"Type")==0)
    assignType(question, string_after);
    else if(strcmp(string_before,"Difficulty")==0)
    assignDiff(question, string_after);
    else if(strcmp(string_before,"Opt")==0)
    assignOpt(question, string_after);
    else if(strcmp(string_before,"Ans")==0)
    assignAns(question, string_after);

    return ;
}

void assignType(Question_B question, char* string_after)
{
    //we now know its to be set for type
    int Len = strlen(string_after);
    for(int i=0;i<Len;i++)
    {
        string_after[i]= toupper(string_after[i]);
        //we are making sure MCQ or McQ or Mcq or mCQ all give same
    }
    question.type = string_after;

    return;
}

void assignDiff(Question_B question, char* string_after)
{
    //we have the values of the format 0.xyz..., which we have to carefully convert
    int Len = strlen(string_after);
    //no.of digits is Len - 2;   (0 and ".")
    double value = 0;
    for(int i=2;i<Len;i++)
    {
        value = value +string_after[i];
        value = value*10;
    }
    //this we'll have value = the number xyz....
    //to make it decimal divide it with 10^(len-1)
    value = value/ pow(10,Len-1);
    question.difficulty = value;

    return;
}

void assignOpt(Question_B question, char* string_after)
{
    // we have options of format abcdef,ghijkl,mnopq,lolkma etc
    // first we need to know the number of options, for this we can check by number of commas
    int Len = strlen(string_after);
    int CommaCount=0;
    for(int i=0;i<Len;i++)
    {
        if(string_after[i]==',')
        CommaCount++;
    }
    //no,of options is No.of commas +1
    CommaCount++;
    //Now this is the count of options.
    char* * array;
    question.no_options = CommaCount;
    question.options =
}

void assignAns(Question_B question, char* string_after)
{
    question.correct_option = string_after;
    return;
}
