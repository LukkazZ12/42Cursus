import os

from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent

SECRET_KEY="093t!^%s@qn1lazs4donw)oh9z&x9os!+9l&_lk9)4mmji8)1)"
DEBUG = False

ALLOWED_HOSTS = ["*"]

INSTALLED_APPS = [
    'games_app',
    'games_worker',
    'channels',
]

CHANNEL_LAYERS = {
    'default': {
        'BACKEND': 'channels_redis.core.RedisChannelLayer',
        'CONFIG': {
            'hosts': [(os.environ.get("REDIS_HOST", "localhost"), int(os.environ.get("REDIS_PORT", 6379)))],
            "expiry": 60,
        },
    },
}

MIDDLEWARE = [
    "django.middleware.common.CommonMiddleware",
    "game_project.middlewares.ExceptionMiddleware",
]

DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.postgresql',
        'NAME': os.environ.get('DB_NAME', 'GAME_CORE_DB'),
        'USER': os.environ.get('DB_USER', 'db_user'),
        'PASSWORD': os.environ.get('DB_PASSWORD', 'example'),
        'HOST': os.environ.get('DB_HOST', '0.0.0.0'),
        'PORT': os.environ.get('DB_PORT', '5433'),
    }
}

LOGGING = {
    'version': 1,
    'disable_existing_loggers': False,
    'formatters': {
        'verbose': {
            'format': '{levelname} {asctime} {name} {message}',
            'style': '{',
        },
        'simple': {
            'format': '{levelname} {message}',
            'style': '{',
        },
    },
    'handlers': {
        'console': {
            'level': 'DEBUG',  # Captura todos os níveis
            'class': 'logging.StreamHandler',
            'stream': 'ext://sys.stdout',  # Garante que a saída seja o terminal padrão
            'formatter': 'verbose',  # Formato detalhado
        },
    },
    'loggers': {
        'django': {
            'handlers': ['console'],
            'level': 'DEBUG',  # Captura todos os níveis do Django
            'propagate': True,
        },
        '': {  # Logger raiz captura todos os logs, incluindo bibliotecas externas
            'handlers': ['console'],
            'level': 'DEBUG',  # Captura todos os níveis
            'propagate': False,
        },
    },
}

ROOT_URLCONF = "game_project.urls"

WSGI_APPLICATION = "game_project.wsgi.application"
ASGI_APPLICATION = "game_project.asgi.application"

AUTH_PASSWORD_VALIDATORS = []

LANGUAGE_CODE = "en-us"

TIME_ZONE = "UTC"

USE_I18N = True

USE_TZ = True

DEFAULT_AUTO_FIELD = "django.db.models.BigAutoField"
