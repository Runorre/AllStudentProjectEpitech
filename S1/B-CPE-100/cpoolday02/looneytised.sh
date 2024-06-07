#!/bin/sh
sed "s/theo1/Wile E. Coyote/g" | sed "s/steven1/Daffy Duck/g" | sed "s/arnaud1/Porky Pig/g" | sed "s/pierre-jean/Marvin the Martian/g" | grep "Wile E. Coyote\|Daffy Duck\|Porky Pig\|Marvin the Martian"
echo "cat passwd"
