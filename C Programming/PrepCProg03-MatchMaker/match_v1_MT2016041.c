#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* corpus[200];
    char* target_words[1000];
    char* corpus_words[1000];
    char* temp = "";
    int iterator = 0, line_iterator = 0, num_of_lines = 0, word_iter = 0, no_of_words_target = 0, no_of_corpusline_words = 0, word_iterator1 = 0, word_iterator2 = 0, matching_terms = 0;
    float match_score = 0.0;
    // Input Redirection - read from the file input.txt
    corpus[iterator] = (char*)malloc(sizeof(char)*1000);
    while(scanf("%[^\n]%*c", corpus[iterator++]) == 1)
        corpus[iterator] = (char*)malloc(sizeof(char)*1000);
    
    num_of_lines = iterator;
    
    printf("%s\n", corpus[0]);
    
    // Tokenize TARGET line:
    word_iter = 0;
    temp = strtok(corpus[0], " ");
    while(temp != NULL) {
        target_words[word_iter++] = temp;
        temp = strtok(NULL, " ");
        no_of_words_target ++;
    }
 
   // Tokenize the strings:
    for(iterator = 1; iterator < num_of_lines - 1; iterator++) {
        word_iter = 0;
        no_of_corpusline_words = 0;
        temp = strtok(corpus[iterator], " ");
        while(temp != NULL) {
            corpus_words[word_iter++] = temp;
            temp = strtok(NULL, " ");
            no_of_corpusline_words ++;
        }
        
        // Find the matching terms with the TARGET:
        matching_terms = 0;
        for(word_iterator1 = 0; word_iterator1 < no_of_words_target; word_iterator1++) {
            for(word_iterator2 = 0; word_iterator2 < no_of_corpusline_words; word_iterator2++) {
                if((strcmp(target_words[word_iterator1], corpus_words[word_iterator2])) == 0) {
                    matching_terms++;
                    break;
                }
            }
            
        }
        
        match_score = (float)matching_terms / (float)(no_of_corpusline_words + no_of_words_target - matching_terms);
        printf("%.2f:", match_score);
        for(word_iterator2 = 0; word_iterator2 < no_of_corpusline_words; word_iterator2++) {
            if(word_iterator2 == no_of_corpusline_words - 1)
                printf("%s", corpus_words[word_iterator2]);
            else
                printf("%s ", corpus_words[word_iterator2]);
        }
        
    }
   
    return 0;
}