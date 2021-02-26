from flask import Flask, render_template, request

app = Flask(__name__)
fib_nums = [0, 1]


def fib(N):
	if N > len(fib_nums):
		return fib(N - 1) + fib(N - 2)
	elif N == len(fib_nums):
		fib_nums.append(fib(N - 1) + fib(N - 2))
	return fib_nums[N]


@app.route('/', methods=['post', 'get'])
def index():
  message = ''
  if request.method == "POST":
    get_num = int(request.form.get('num'))
    message = 'Число Фибоначчи ' + str(get_num) + ' = ' + str(fib(get_num))
  return render_template('index.html', message=message)


if __name__ == "__main__":
  app.run(host="0.0.0.0")