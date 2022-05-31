var convert = function(s, numRows) {
    if( numRows <= 1 ){
        return s;
    }
    let i, row = 0;
    let down = true;
    let array = [];
    for( i = 0; i < numRows; i++ ){
        array[i] = "";
    }
    for( i = 0; i < s.length; i++ ){
        array[row] += s[i];
        if( row == 0 ){
            down = true;
        }
        if( row == numRows - 1 ){
            down = false;
        }
        down ? row++ : row--;
    }
    var answer = "";
    for( i = 0; i < numRows; i++ ){
        answer += array[i];
    }
    return answer;
};
