#include <stdio.h>
#include <time.h>

#include "misc.h"
#include "compilation_tower.h"

int main(int argc, char const* const* argv) {
	if (argc != 2)
		panic("expected 2 command line arguments");

	compilation_tower_t tower = create_compilation_tower(argv[1]);
    compilation_tower_read_file(&tower);

    clock_t tokenizer_start = clock();
    compilation_tower_tokenizer(&tower);
    clock_t tokenizer_end = clock();
    clock_t tokenizer_time = tokenizer_end - tokenizer_start;

    printf("tokenization_time: %lfms\n", (double)tokenizer_time / CLOCKS_PER_SEC * 1000);
    
    /*
    // compilation_tower_dparser(&tower);
    // compilation_tower_semanalyzer(&tower);

    for (size_t i = 0; i < tower.tokens.string_values.length; i++) {
        fprintf(stderr, "i: %u, l: %u, s: %.*s\n", i, tower.tokens.string_values.lengths[i], tower.tokens.string_values.lengths[i], tower.tokens.string_values.contents[i]);
    }

    fprintf(stderr, "-\n");

    for (size_t i = 0; i < tower.tokens.length; i++) {
        fprintf(stderr, "k: %d, v: %u\n", tower.tokens.kinds[i], tower.tokens.values[i]);
    }
    */

    drop_compilation_tower(&tower);
	return 0;
}
