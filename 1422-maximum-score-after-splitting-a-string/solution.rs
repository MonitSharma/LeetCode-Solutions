impl Solution {
    pub fn max_score(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let mut left_zeros = 0;
        let mut right_ones = chars.iter().filter(|&&c| c == '1').count() as i32;
        let mut max_score = 0;


        for i in 0..chars.len()-1 {
            if chars[i] == '0' {
                left_zeros += 1;

            } else {
                right_ones -= 1;

            }

            max_score = max_score.max(left_zeros + right_ones);
        }

        max_score
        
    }
}