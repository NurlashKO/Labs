from django.http import HttpResponse
from .models import Question
from django.template import loader

# Create your views here.
def index(requests):
    latest_question_list = Question.objects.order_by('-pub_date')[:5]
    template = loader.get_template('polls/index.html')
    context = {
        'latest_question_list':latest_question_list,
    }
    return HttpResponse(template.render(context, requests))

def detail(requests, question_id):
    return HttpResponse("You're looking at question %s." % question_id)

def results(requests, question_id):
    response = "You're looking at results of question %s."
    return HttpResponse(response % question_id)

def vote(requests, question_id):
    return HttpResponse("You're voting on question %s." % question_id)
