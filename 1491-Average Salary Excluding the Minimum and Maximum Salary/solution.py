class Solution:
    def average(self, salary: List[int]) -> float:
        min_salary = min(salary)
        max_salary = max(salary)
        total_salary = sum(salary) - min_salary - max_salary
        num_employees = len(salary) - 2
        return total_salary / num_employees