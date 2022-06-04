const MaxUint = ^uint(0)
const MaxInt = int(MaxUint >> 1)

func absInt(x int) int{
    if x < 0 {
        return x*-1
    }

    return x
}

func threeSumClosest(nums []int, target int) int {
    numsLength := len(nums)
    if numsLength < 3 {
        return 0
    }

    sort.Ints(nums)

    i, sum := 0, 0
    minDiff := MaxInt

    for i < numsLength - 2 {
        left := i + 1
        right := numsLength - 1

        for right > left {
            temp := nums[i] + nums[left] + nums[right]
            diff := absInt(temp - target)

            if diff == 0 {
                return target
            }

            if diff < minDiff {
                minDiff = diff
                sum = temp
            }

            if temp < target {
                left++
            } else {
                right--
            }
        }

        i++
    }

    return sum
}
