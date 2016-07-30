#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char* corpus[200];
    char* targets[200];
    char* vocab_words[100];
    char* target_words[30];
    char* corpus_words[30];
    char* corpus_vocab_words[30];
    char* temp = "";
    char* temp1 = "";
    char* temp2 = "";
    char* result = "";
    int iterator = 0, line_iterator = 0, num_of_corpus_lines = 0, word_iter = 0, no_of_words_target = 0, no_of_corpusline_words = 0, word_iterator1 = 0, word_iterator2 = 0, matching_terms = 0, no_of_words_vocab = 0, num_of_targets = 0;
    int iterator0 = 0, no_of_targetline_words = 0, iterate_each_line = 0, word_iterator3 = 0, no_of_corpus_words_in_vocab = 0;
    float match_score = 0.0, max_match_score = 0.0;
    
    // Read from the file corpus.txt
    FILE* corpus_fp = fopen(argv[1],"r");
    corpus[iterator] = (char*)malloc(sizeof(char)*300);
    while(fscanf(corpus_fp, "%[^\n]%*c", corpus[iterator++]) == 1)
        corpus[iterator] = (char*)malloc(sizeof(char)*300);
    
    num_of_corpus_lines = iterator - 1;
      
    fclose(corpus_fp);
    // Read from the file targets.txt
    FILE* target_fp = fopen(argv[2],"r");
    iterator = 0;
    targets[iterator] = (char*)malloc(sizeof(char)*300);
    while(fscanf(target_fp, "%[^\n]%*c", targets[iterator++]) == 1)
        targets[iterator] = (char*)malloc(sizeof(char)*300);
    
    num_of_targets = iterator;
	fclose(corpus_fp);
    // Tokenize VOCAB line:
    word_iter = 0;
    temp = strtok(corpus[0], " ,");
    while(temp != NULL) {
        vocab_words[word_iter++] = temp;
        temp = strtok(NULL, " ,");
        no_of_words_vocab ++;
    }
    
	// Open the file to store the results
	FILE* matches_fp = fopen(argv[3], "w");
	
	for(iterator0 = 0; iterator0 < num_of_targets - 1; iterator0++) {
		// Tokenize the targets one by one:
		word_iter = 0;
        no_of_targetline_words = 0;
        temp = strtok(targets[iterator0], " ,");
        while(temp != NULL) {
            target_words[word_iter++] = temp;
            temp = strtok(NULL, " ,");
            no_of_targetline_words ++;
        }
        // Now target_words[iterator0] contains the tokenized words of the target line
        // print the target line on to the matches.txt file
        for(word_iterator2 = 0; word_iterator2 < no_of_targetline_words; word_iterator2++)
        	if(word_iterator2 == no_of_targetline_words - 1)
        		fprintf(matches_fp, "%s;", target_words[word_iterator2]);
        	else
        		fprintf(matches_fp, "%s,", target_words[word_iterator2]);
        
        // Match the target line words with each and every line of the corpus line and find the maximum match score
    
        max_match_score = 0;
        for(iterate_each_line = 0; iterate_each_line < num_of_corpus_lines; iterate_each_line++) {
			// Tokenize the strings:
    		for(iterator = 1; iterator < num_of_corpus_lines; iterator++) {
        		word_iter = 0;
        		no_of_corpusline_words = 0;
        		temp2 = (char*)malloc(sizeof(char)*strlen(corpus[iterator]));
        		strcpy(temp2, corpus[iterator]);
        		temp = strtok(temp2, " ,");
        		while(temp != NULL) {
            		corpus_words[word_iter++] = temp;
            		temp = strtok(NULL, " ,");
            		no_of_corpusline_words ++;
        		}
        		// Now corpus_words[iterator] contains the tokenized words of the corpus line
        	
        		// Compare the corpus line words with the words of the vocab and copy corpus words that are from vocab into another array
        		word_iterator3 = 0;
        		for(word_iterator1 = 0; word_iterator1 < no_of_corpusline_words; word_iterator1++) {
            		for(word_iterator2 = 0; word_iterator2 < no_of_words_vocab; word_iterator2++) {
                		if((strcmp(corpus_words[word_iterator1], vocab_words[word_iterator2])) == 0) {
                			
                			temp1 = (char*)malloc(sizeof(char)*strlen(corpus_words[word_iterator1]));
                			strcpy(temp1,corpus_words[word_iterator1]);
                    		corpus_vocab_words[word_iterator3] = temp1;
                    		word_iterator3++;
                		}
            		}
        		}
        		no_of_corpus_words_in_vocab = word_iterator3;
        		
        		// Find the matching terms with the TARGET:
        		matching_terms = 0;
        		for(word_iterator1 = 0; word_iterator1 < no_of_targetline_words; word_iterator1++) {
            		for(word_iterator2 = 0; word_iterator2 < no_of_corpus_words_in_vocab; word_iterator2++) {
                		if((strcmp(target_words[word_iterator1], corpus_vocab_words[word_iterator2])) == 0) {
                    		matching_terms++;
                    		break;
                		}
            		}
        		}
        		match_score = (float)matching_terms / (float)(no_of_corpus_words_in_vocab + no_of_targetline_words - matching_terms);
        		if(match_score > max_match_score) {
        			max_match_score = match_score;
        			result = corpus[iterator];
        		}
        	}
        	
    	}
    	fprintf(matches_fp, "%.2f:", max_match_score);
        fprintf(matches_fp, "%s", result);
     	fprintf(matches_fp, "\n");
	}
	fclose(matches_fp);
    return 0;
}