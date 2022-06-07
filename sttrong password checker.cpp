class Solution {
public:
    int strongPasswordChecker(string s) {
        // For diversity requirement.
        bool lower_case(false), upper_case(false), digit(false);
        
        // For repeats.
        std::vector<int> run_lengths;

        char curr;
        int run_length(0);
        for (int i = 0; i < s.size(); ++i) {
            // Do we need new characters.
            if (s[i] >= 'a' && s[i] <= 'z') {
                lower_case = true;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                upper_case = true;
            } else if (s[i] > '0' && s[i] <= '9') {
                digit = true;
            }
            
            // Repeats.
            if (i == 0) {
                curr = s[0];
                run_length = 1;
                continue;
            }
            if (s[i] == curr) {
                ++run_length;
            } else {
                if (run_length >= 3) {
                    run_lengths.push_back(run_length);
                }
                curr = s[i];
                run_length = 1;
            }
        }
        if (run_length >= 3) {
            run_lengths.push_back(run_length);
        }

        // Number of new characters needed.
        int num_new(0);
        if (!lower_case) {
            ++num_new;
        }
        if (!upper_case) {
            ++num_new;
        }
        if (!digit) {
            ++num_new;
        }
        
        // We can resolve some repeats if we need to insert or delete characters.
        int num_edits(0);
        if (s.size() < 6) {
            int num_inserts = 6 - s.size();
            // Some of the inserts can also satisfy num_new.
            num_new -= min(num_new, num_inserts);
            // Some of the inserts can break run lengths.
            for (int i = 0; i < run_lengths.size(); ++i) {
                int rl = run_lengths[i];
                while (num_inserts > 0 && rl >= 3) {
                    --num_inserts;
                    ++num_edits;
                    rl -= 2;
                }
                while (num_new > 0 && rl >= 3) {
                    --num_new;
                    ++num_edits;
                    rl -= 2;
                }
                run_lengths[i] = rl;
            }
            num_edits += num_inserts;
        } else if (s.size() > 20) {
            int num_deletes = s.size() - 20;
            // Some of the deletes can break run lengths at the same priority as substitutions.
            for (int i = 0; i < run_lengths.size(); ++i) {
                int rl = run_lengths[i];
                while (num_new > 0 && rl >= 3) {
                    --num_new;
                    ++num_edits;
                    rl -= 3;
                }
                if (rl >= 3 && num_deletes > 0 && rl % 3 == 0) {
                    --num_deletes;
                    ++num_edits;
                    rl -= 1;
                }
                run_lengths[i] = rl;
            }
            // Use the remainder of our deletion budget by priority.
            // This is given by number of deletes needed to break a repeat.
            for (int i = 0; i < run_lengths.size(); ++i) {
                int rl = run_lengths[i];
                if (rl >= 3 && num_deletes >= 2 && rl % 3 == 1) {
                    num_deletes -= 2;
                    num_edits += 2;
                    rl -= 2;
                }
                run_lengths[i] = rl;
            }
            for (int i = 0; i < run_lengths.size(); ++i) {
                int rl = run_lengths[i];
                while (rl >= 3 && num_deletes >= 3 && rl % 3 == 2) {
                    num_deletes -= 3;
                    num_edits += 3;
                    rl -= 3;
                }
                run_lengths[i] = rl;
            }
            num_edits += num_deletes;
        }
        
        // All remaining repeats will now be broken by substitutions.
        int num_replace(0);
        for (int rl : run_lengths) {
            num_replace += rl / 3;
        }
        num_edits += num_replace;
        
        // Some num_new can be satisfied by above substitutions.
        num_new -= min(num_new, num_replace);
        num_edits += num_new;

        return num_edits;
    }
};
